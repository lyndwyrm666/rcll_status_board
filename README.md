# rcll_status_board

This package provides ROS nodes to visualize the RoboCup Logistics League (RCLL) gameplay.

## Getting Started

### Prerequisites

The following software is required to run this package:

ROS Indigo (including OpenCV 2.x): (e.g. sudo apt-get install ros-indigo-desktop-full), see [ROS Indigo Install Ubuntu](http://wiki.ros.org/indigo/Installation/Ubuntu) for installation process

Installed RCLL refbox (see [RCLL refbox installation](https://trac.fawkesrobotics.org/wiki/RCLLRefBox/Install))

The following ROS packages are required to run this package:

- [rcll_vis_msgs](https://github.com/ethflo/rcll_vis_msgs)
- [protobuf_comm](https://github.com/ethflo/protobuf_comm)
- [llsf_msgs](https://github.com/ethflo/llsf_msgs)

### Installing

Install the required software, create a catkin workspace (see [create ROS catkin workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)) and download the required ROS packages into the workspaces src folder.

Adjust the *llsf_msgs* packages to your system. Therefore set the REFBOX_ROOT_DIR path variable in the CMakeLists.txt file to your refbox installation path. (See also [llsf_msgs](https://github.com/ethflo/llsf_msgs) readme)

```
(in CMakeLists.txt)
...
set(REFBOX_ROOT_DIR /home/username/llsf-refbox)
...
```

Build your catkin workspace (you will have to build the workspace again each time you update one of the ROS packages or the refbox)

```
cd ~/catkin_ws
catkin_make
```

### Usage

Start the status boards. You need to start one launchfile, which starts a node providing the data, and at least one launchfile, which starts one of the displaying nodes. The following launchfiles exist:

Launchfiles providing the data:
- comm.launch establishes the communication to the refbox and provides the data from there. If you use a remote refbox you have to adjust the refboxes ip in the launchfile.
- dummy.launch provides static data for testing purposes.

Launchfiles displaying the data:
- cyan.launch starts the team status board for the cyan team.
- magenta.launch starts the team status board for the magenta team.
- field.launch starts the field status board.

You will need a new terminal window for each launchfile you start.

Example:
```
Terminal1: roslaunch rcll_status_board comm.launch
Terminal2: roslaunch rcll_status_board field.launch
```

Further there exists a launchfile all.launch, which starts the communication to the refbox and all status boards in one terminal window.

## Versioning

For the versions available, see the [github repository](https://github.com/ethflo/rcll_status_board).

For creating and using a dockerized version of the status board see the repository [rcll_status_board_docker](https://github.com/ethflo/rcll_status_board_docker).

## Authors

* **Florian Eith** - *Initial work* - [Florian Eith](https://github.com/ethflo)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* Thanks to the developers of the RCLL Refbox
* Inspirated by a concept of the RCLL Team Lueneburg 2016


