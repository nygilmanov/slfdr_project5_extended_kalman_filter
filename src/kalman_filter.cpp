#include "kalman_filter.h"

#define EPS 0.0001 // A very small number


using Eigen::MatrixXd;
using Eigen::VectorXd;

/* 
 * Please note that the Eigen library does not initialize 
 *   VectorXd or MatrixXd objects with zeros upon creation.
 */

KalmanFilter::KalmanFilter() {}
// Kalman filter equations 


KalmanFilter::~KalmanFilter() {}

void KalmanFilter::Init(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
  x_ = x_in;
  P_ = P_in;
  F_ = F_in;
  H_ = H_in;
  R_ = R_in;
  Q_ = Q_in;
}


void KalmanFilter::Predict() {
  // Same for linear and extended KF
  x_ = F_ * x_;
  MatrixXd Ft = F_.transpose();
  P_ = F_ * P_ * Ft + Q_;
}


void KalmanFilter::Update(const VectorXd &z) {
  VectorXd z_pred = H_ * x_;
  VectorXd y      = z - z_pred;

  CommonUpdate(y);
}


void KalmanFilter::UpdateEKF(const VectorXd &z) {
  /**
    * update the state by using Extended Kalman Filter equations
  */
  double rho     = sqrt(x_(0)*x_(0) + x_(1)*x_(1));
  double theta   = atan2(x_(1), x_(0));
  double rho_dot;

  if (fabs(rho) < EPS) {
    rho_dot = 0;
  } else {
    rho_dot = (x_(0)*x_(2) + x_(1)*x_(3)) / rho;
  }

  VectorXd h = VectorXd(3);

  h << rho, theta, rho_dot;

  VectorXd y = z - h;
  
 
  // Normalize angle to within -PI and PI if needed
  while (y(1) > 2*M_PI || y(1) < -2*M_PI)
  {
    if (y(1) > 2*M_PI) y(1) -= 2*M_PI;
    else if (y(1) < -2*M_PI) y(1) += 2*M_PI;
  }

  CommonUpdate(y);
}
  
  

void KalmanFilter::CommonUpdate(const VectorXd &y){

  MatrixXd Ht  = H_.transpose();
  MatrixXd S   = H_ * P_ * Ht + R_;
  MatrixXd Si  = S.inverse();
  MatrixXd PHt = P_ * Ht;
  MatrixXd K   = PHt * Si;

  //new estimate
  x_ = x_ + (K * y);
  long x_size = x_.size();
  MatrixXd I = MatrixXd::Identity(x_size, x_size);
  P_ = (I - K * H_) * P_;
}
  

  
  

  
  
 
