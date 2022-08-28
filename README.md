![](assets/images/banner.png)



<img src="assets/images/htb.png" style="margin-left: 20px; zoom: 60%;" align=left />    	<font size="10">Safe Box</font>

​		28<sup>th</sup> August 2022

​		Challenge Author: Abhishek Agarwal 

​		
### Description:

Welcome to your bank. It seems like you stored something important in your safe box the last time you were here. You also said something about hiding your key afterwards. Wheww! who can remember. Anyhow, just enter your key and retrieve your contents.   

### Objective

To retreive the flag, input the correct key. Reverse engineer the binary to figure out the key.    
This challenge involves debugging and disassembly, bypasssing anti-debugging techniques, and reading assembly code to decrypt a string.

### Difficulty:

`medium`

### Flag:

`HTB{Y()uR_M!LL!()N$$}`


# Challenge

The challenge file is a 64-bit ELF (linux binary) file, by the name of `safebox`. The source code and Makefile can be found in the **code** folder. The challenge is written in C and uses gcc for compilation. Use the *make* and *make clean* commands to build the challenge and clean the files respectively.

A pre-built challenge file can also be found on the main path: [Safebox](safebox)


# Solver

The **solver** folder contains the automatic sovler for this challenge. It is a short python script which runs the challenge, inputs the key and retrieves the flag. The flag is stored in a file called **flag.txt**.    

To run the solver, follow the below mentioned steps:

- Run the *make* command from the **code** folder. This builds the challenge and stores a copy in the **solver** folder.
- Then run the below mentioned command in the **solver** folder.

    ```bash
    python3 solver.py
    ```

