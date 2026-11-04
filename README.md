# OS Lab – CPU Scheduling Algorithms

A collection of C implementations of fundamental CPU scheduling algorithms for the Operating Systems Laboratory.

## Algorithms Implemented

| Algorithm | Description |
|---|---|
| FCFS | First Come First Serve |
| SJF | Shortest Job First |
| Priority | Priority Scheduling |
| Round Robin | Time Quantum Based Scheduling |
| MQS | Multilevel Queue Scheduling |

## Features

- Process scheduling based on arrival and burst time
- Calculation of Completion Time (CT)
- Calculation of Turnaround Time (TAT)
- Calculation of Waiting Time (WT)
- Average Turnaround Time and Waiting Time

## Technologies Used

- Programming Language: C
- IDE: Visual Studio Code
- Platform: Windows

## Repository Structure

```text
OS-Lab-CPU-Scheduling/
│
├── FCFS.c
├── SJF.c
├── Priority.c
├── RoundRobin.c
├── MQS.c
└── README.md
```

## How to Run

Compile any source file using GCC:

```bash
gcc FCFS.c -o FCFS
```

Run the program:

```bash
./FCFS
```

Replace `FCFS.c` with the desired source file to run another scheduling algorithm.

## Academic Information

**Course:** Operating Systems Laboratory  
**Project:** CPU Scheduling Algorithms  
**Language:** C

---

This repository is created for academic learning and practical understanding of CPU scheduling concepts.
