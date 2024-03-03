# Seat-Auto-Adjustment
## Project Objective 
the project is a part of on job training at SeiTech Solutions, The project aims to be get familiar with embedded linux and yocto project.

## Project Requirements 
### Problem statement 
Automatically adjust the seat for optimal comfort and safety based on the driver's physical characteristics.
### User needs
- Easy user interface for entering the inputs.
- Auto-positioning with less manual modifications.
- Easy feedback process after positioning.
- Comfort seat position for driving, holding the pedal, and clear vision.
### Guidelines
#### Word Glossary
Conditions:  
>H = Height  
W = Weight  

Actions:  
>SP = Standard Seat Position  
SHF = Seat Higher and Further Front  
SLB = Seat Lower and Further Back  
DLS = Decreased Lumbar Support and Slightly Raised Backrest  
ILS = Increased Lumbar Support and Slightly Reclined Backrest  


Conditions:  
>MinAvgH = Minimum Average Height  
MaxAvgH = Maximum Average Height  
MinAvgW = Minimum Average Weight  
MaxAvgW = Maximum Average Weight  

Inputs:  
>UH = Undefined Height Action  
UW = Undefined Weight Action  

#### All Possible Conditions 
- If minimum average <= weight & height =< maximum average 🡪 standard seat position.

- If height <= minimum average 🡪 seat higher and further front.

- If height >= maximum average 🡪 seat lower and further back.

- If weight <= minimum average 🡪 decreased lumbar support and a slightly raised backrest.

- If weight >= maximum average 🡪 increased lumbar support and a slightly reclined backrest.  

#### Seat Parameters
![Seat Parameters](./assets/SeatParameters.png)

## Project Architecture
### System Architecture
![System Architecture](./assets/sysArch.PNG)
### Software Architecture
![Software Architecture](./assets/swArch.PNG)
### Project Layers based on Linux Layered Architecture
![Project Layered](./assets/LayeredArch.png)
### System Partitioning
![System Partitioning](./assets/part.PNG)
### System Sequence diagram
![Sequence diagram](./assets/seg.png)