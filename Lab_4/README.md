This is the first snapshot of doing the task steps:

<img width="740" alt="task41" src="https://github.com/user-attachments/assets/109e8b09-fc2c-452e-9346-ab74a13c530e">


But I got these below two errors while installing the iverilog and gtkwave packages:

E: Could not get lock /var/lib/dpkg/lock-frontend - open (11: Resource temporarily unavailable)
E: Unable to acquire the dpkg frontend lock (/var/lib/dpkg/lock-frontend), is another process using it?

After that, I typed sudo reboot and tried to install the packages again and it succeeds now.
<img width="740" alt="image" src="https://github.com/user-attachments/assets/ea159194-c5ab-4540-b7a7-710695cac5ea">

Then, I edited the testbench to change the name of the vcd to task4 as shown in the below snapshot
<img width="964" alt="task43" src="https://github.com/user-attachments/assets/69b66f72-bd25-4ceb-a00c-8a559aa38bee">

After that I run the below commands
<img width="964" alt="task44" src="https://github.com/user-attachments/assets/97d74fc1-0d08-4423-97b4-a16a33cbe2fd">

The instructions that should be debugged are hardcoded in the RTL in RISCV core as below
<img width="964" alt="task451" src="https://github.com/user-attachments/assets/fe04c370-60d9-4adb-a2bd-76f00d7a0975">

The debugging of the output vcd is shown below
<img width="964" alt="452" src="https://github.com/user-attachments/assets/eb29d2b0-ec9b-4405-a618-aa7d64e5d4b6">
