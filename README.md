![](assets/images/banner.png)



<img src="assets/images/htb.png" style="margin-left: 20px; zoom: 60%;" align=left />    	<font size="10">Safe Box</font>

​		28<sup>th</sup> August 2022

​		Challenge Author: Abhishek Agarwal 

​		
### Description:

Welcome to your bank. It seems like you stored something important in your safe box the last time you were here. You also said something about hiding your key afterwards. Wheww! who can remember. Anyhow, just enter your key and retrieve your contents.   

### Objective

The objective of this challenge is to retreive the flag by entering the correct key. The participants will have to reverse engineer the challenge file to figure out the key.        
This challenge involves debugging and disassembling the code, bypasssing anti-debugging technique, and reading assembly to understand key decryption and validation logic.

### Difficulty:

`medium`

### Flag:

`HTB{Y()uR_M!LL!()N$$}`


# Challenge

The challenge file is a 64-bit ELF (linux binary) file, by the name of `safebox`. The source code and Makefile can be found in the **code** folder. The challenge is written in C and uses gcc for compilation. Use the *make* and *make clean* commands to build the challenge and clean the files respectively.

A pre-built challenge file can also be found on the main folder path: [Safebox](safebox)


# Solver

The **solver** folder contains the automatic sovler for this challenge. It is a short python script which runs the challenge, inputs the key and retrieves the flag. The flag is stored in a file called **flag.txt**.    

To run the solver, follow the below mentioned steps:

- Run the *make* command from the **code** folder. This builds the challenge and stores a copy of the executable in the **solver** folder.
- Then run the below mentioned command in the **solver** folder.

    ```bash
    python3 solver.py
    ```

# Directory Structure

Below is the directory strucutre of the challenge submission folder.

```
|---- assets
|---- code
        |---- Makefile
        |---- safebox.c
        |---- safebox
|---- safebox
|---- solver
        |---- solver.py
        |---- safebox
|---- walkthrough
        |---- writeup.md
|---- README.md
```

- _assets:_ This folder contains the image assets - both HTB assets and images for walkthrough writeup.
- _code:_ The code folder contains the C source code, the Makefile and the executable file.
- _safebox_: This is the challenge executable file. Two other copies of this file can be also found in the **solver** and **code** folder.
- _solver:_ This folder contains the python solver script along with the copy of the executable file.
- _walkthrough:_ This folder contains the writeup document.
- _README.MD:_ This is the main README for the challenge.