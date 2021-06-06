# Extended Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program

In this project you will utilize a kalman filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. Passing the project requires obtaining RMSE values that are lower than the tolerance outlined in the project rubric. 

This project involves the Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).



## The project has the following dependencies

The project has the following dependencies (from Udacity's seed project):

- cmake >= 3.5
- make >= 4.1
- gcc/g++ >= 5.4
- Udacity's simulator.

For instructions on how to install these components on different operating systems, please, visit Udacity's seed project. As this particular implementation was done on Mac OS, the rest of this documentation will be focused on Mac OS. I am sorry to be that restrictive.

In order to install the necessary libraries, use the install-mac.sh.
## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./ExtendedKF `


## Running the Filter
From the build directory, execute `../ExtendedKF.`. The output should be:


```sh
Listening to port 4567
Connected!!!
```


## [Rubric points](https://review.udacity.com/#!/rubrics/748/view) 


### Compiling

Code compiles without any errors

[CMackeLists.txt](./CMakeLists.txt) 


### Accuracy

### px, py, vx, vy output coordinates must have an RMSE <= [.11, .11, 0.52, 0.52] when using the file: "obj_pose-laser-radar-synthetic-input.txt which is the same data file the simulator uses for Dataset 1"


#### Radar and lidar measurements 

| RMSE | Dataset 1 | Dataset 2 |
|------|-----------|-----------|
| P x  |  0.0974   |  0.0726   |
| P y  |  0.0885   |  0.0965   |
| V x  |  0.4517   |  0.4219   |
| V y  |  0.0404   |  0.4937   |


#### Radar  measurements 

| RMSE | Dataset 1 | Dataset 2 |
|------|-----------|-----------|
| P x  |  11.1947   |  0.2709   |
| P y  |  8.1495   |  0.3857   |
| V x  |  9.1877   |  0.6530   |
| V y  |  6.9924   |  0.9227   |



#### Lidar measurements 

| RMSE | Dataset 1 | Dataset 2 |
|------|-----------|-----------|
| P x  |  0.1474   |  0.1169   |
| P y  |  0.1154   |  0.1262   |
| V x  |  0.6390   |  0.6231   |
| V y  |  0.5351   |  0.6030   |



# The  results of the  various runs 

## Radar&Lidar measurements
![Model](./IMGS/RLD1.png)
![Model](./IMGS/RLD2.png)

## Radar measurements
![Model](./IMGS/RD1.png)
![Model](./IMGS/RD2.png)

## Lidar measurements
![Model](./IMGS/LD1.png)
![Model](./IMGS/LD2.png)


## Hints and Tips!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.
* Students have reported rapid expansion of log files when using the term 2 simulator.  This appears to be associated with not being connected to uWebSockets.  If this does occur,  please make sure you are conneted to uWebSockets. The following workaround may also be effective at preventing large log files.

    + create an empty log file
    + remove write permissions so that the simulator can't write to log
 * Please note that the ```Eigen``` library does not initialize ```VectorXd``` or ```MatrixXd``` objects with zeros upon creation.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to ensure
that students don't feel pressured to use one IDE or another.

However! We'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Regardless of the IDE used, every submitted project must
still be compilable with cmake and make.

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

