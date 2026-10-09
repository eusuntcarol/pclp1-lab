This lab we focus on bringing alive our environments, so everyone will be able to compile and execute C binaries.  

# Prerequisites

1. Install a text editor, [Visual Studio Code](https://code.visualstudio.com/) is recommended.
1. Open extensions tab in VSC in the left-side panel by pressing the following icon: <img src="./assets/extensions.png" alt="extensions icon" width="25">
1. Find and install `C/C++` extension.  
   Note: If you are using WSL, this should be installed again after you are connected to the WSL instance (`Install in WSL`).

# Windows setup

### WSL2 way (*recommended*)
1. Check that you have virtualization enabled:
    - Open Task Manager
    - Click on the Performance tab, and then click on CPU
    - Look for the Virtualization section and check if it says "Enabled" or "Disabled"
        - IF Virtualization is "Disabled"
        - THEN continue with [How to enable virtualization](#how-to-enable-virtualization) section and repeat from point 1 
        - ELSE continue with next point
1. Open PowerShell with Administrator privileges (right click -> Run as Admin)
1. Run the following command in PowerShell:
    ```powershell
    wsl --install
    ```
1. Restart your laptop
1. Run the following command in PowerShell:
    ```powershell
    wsl --install -d Ubuntu-26.04
    ```
1. Restart your laptop again
1. Open VSC and install `WSL` extension
1. Open the WSL instance by running inside PowerShell: `wsl`. At the first run it will ask you to create a username and password. Choose whatever you want and remember the credentials.
1. Connect to the WSL instance. In the left-bottom corner you might click on that icon then connect to your machine: <img src="./assets/remote.png" alt="remote icon" width="30">
1. Install `C/C++` extension while you are connected to WSL (`Install in WSL` option)
1. Continue with [Linux / WSL2 setup](#linux--wsl2-setup)

#### How to enable virtualization

If Virtualization shows **Disabled**, enable it in BIOS/UEFI:
1. Restart the PC and press the BIOS key during boot (usually `F2`, `F10`, `Del` or `Esc`, depending on the manufacturer).
1. Find the virtualization option, usually under *Advanced*, *CPU Configuration* or *Security*.
   - Intel: **Intel Virtualization Technology** (VT-x)
   - AMD: **SVM Mode** (AMD-V)
1. Set it to **Enabled**, save and exit (usually `F10`).
1. Re-check Task Manager, it should now say "Enabled".
    - IF Virtualization is "Enabled"
    - THEN go back to [WSL2](#wsl2-way-recommended) section and repeat
    - ELSE try another way

The exact menu names differ between manufacturers, so if you can't find it, search for
"enable virtualization <your PC/motherboard model>".

### Virtual Machine way
1. Install a hypervisor. You might choose between VMware and VirtualBox.
1. Download whatever Linux image (.iso) you want then install it on the hypervisor.  
    **PS:** For improved performance and development convenience, I would suggest you to install Ubuntu Server, then connect to the VM using SSH via VSC. Be aware that you won't have GUI installed at all.  
    **PPS:** However, if you don't feel comfortable yet using only the terminal and you need visual feedback, **DO NOT** install a server image and pick one with GUI.
1. Now you can either connect to it via VSC extension or install a text editor inside the VM:
    - Option 1 - any distro. Install `Remote - SSH` extension in VSC.
        - The VM needs SSH service running, install it by running:
            ```bash
            sudo apt update
            sudo apt install openssh-server
            ```
        - Connect to the VM. You will need its local IP address to be able to connect to it using SSH. Check your hypervisor settings so the networking is set to `bridge`.
    - Option 2 - only for Ubuntu with GUI. Install a text editor that you like inside the VM:
        - Visual Studio Code (recommended):
            ```bash
            sudo snap install --classic code
            ```
        - VIM / NeoVIM:
            ```bash
            sudo apt update
            sudo apt install neovim
            nvim <file_name>
            ```
1. Continue with [Linux / WSL2 setup](#linux--wsl2-setup)

### Bare-metal Windows way
If you cannot install WSL2, nor a virtual machine, you can use Windows instead.  
For homeworks you might have problems because they are meant to run in Linux environments.  
For example, one problem is that your executable file won't be `.out`, but `.exe`.

1. [Install MinGW](https://www.geeksforgeeks.org/installing-mingw-tools-for-c-c-and-changing-environment-variable/).
Follow all instructions, including adding the app to PATH.
1. Open `C:\MinGW\bin` folder and locate the `mingw32-make.exe` file and rename it to `make`.
1. Restart your PowerShell and make sure that environment variables are set properly.
If they are, the following commands might succeed:
    ```powershell
    gcc --version
    make --version
    ```
1. Install [GIT](https://git-scm.com/downloads/win).

# Linux / WSL2 setup

Install packages:
```bash
sudo apt update
sudo apt install build-essential
sudo apt install git
```

# macOS setup

Install C dev dependencies and wait for it to finish:
```bash
xcode-select --install
```

# Environment verification

To test whether your environment works as expected or not, run the following commands in the terminal. They must return a version:
```bash
gcc --version
make --version
git --version
```
*Note 1*: Linux, WSL and macOS users should run these commands in the terminal.  
*Note 2*: Bare-metal Windows users should run these commands in PowerShell.

Let's write a simple C program and run it. Create a file `test.c` with the following content:
```c
#include <stdio.h>

int main(void) {
    int a = 1, b = 2;

    printf("%d + %d = %d\n", a, b, a + b);

    return 0;
}
```

Compile the program:
```bash
gcc -Wall -Wextra -Werror test.c -o test
```
This will result in a binary named `test`.  
Command explanation:
- `-o` parameter specifies what should be the name of the resulting binary, in our case `test`. If you omit this param, the produced binary will be named by default `a.out` / `a.exe`.
- `-Wall` parameter tells the compiler to print a larger set of warnings.
- `-Wextra` parameter tells the compiler to print extra warnings beyond `-Wall`.
- `-Werror` parameter turns every warning into an error, so the compilation stops. You should read the message and fix it.

These parameters are optional, but I strongly suggest using them while you learn. In the long run they will help write better code and to catch hidden bugs early.

To run the resulting binary, run the following command:
```bash
./test
```
or, if you are using bare-metal Windows:
```powershell
.\test.exe
```

# Done

**Congrats! 🎉**  
**Now you are ready to begin your PCLP1 journey 🚀**
