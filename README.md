# Prerequisites

1. Install a text editor, preferably [Visual Studio Code](https://code.visualstudio.com/).
2. Open extensions tab in VSC in the left-side panel by pressing the following icon:
![extensions icon](./assets/extensions.png)
3. Find and install `C/C++` extension.

# Windows setup

Once you have WSL2 or a virtual machine set up, you might connect to it using
Visual Studio Code.
In the left-down corner you might click on that icon then connect to your machine:
![remote icon](./assets/remote.png)



### WSL2 way:
***Recommended way***
1. Check that you have virtualization enabled:
- open Task Manager
- click on the Performance tab, and then click on CPU
- look for the Virtualization section and check if it says "Enabled"
or "Disabled"
2. Open PowerShell with Administrator priviledges (right click -> Run as Admin)
3. Run the following commands:
```powershell
wsl install
wsl install ubuntu
```
4. Open the WSL instance:
```powershell
ubuntu
```
5. Install `WSL` extension in VSC.

**NOTE:** If you have problems installing WSL2, you might try to install
a virtual machine instead.

### Virtual Machine way:
1. Install a hypervisor. You might choose between VMWare and VirtualBox.
2. Download whatever Linux image (.iso) you want then install it on the
hypervisor.<br>
**PS:** For improved performance I suggest you to install Ubuntu Server,
then connect to the VM using SSH via VSC.
Be aware that you won't have a GUI installed.<br>
**PPS:** If you don't feel comfortable using only the terminal and you need
visual feedback, **DO NOT** install a server image.

### Pure Windows way
***This approach is not recommended***<br>
If you cannot install WSL2, nor a virtual machine, you can use Windows instead,
but only for lab purposes.<br>
For homeworks you might have problems because they are meant to run in Linux
environments.<br>
For example, one problem is that your executable file won't be `.out`, but `.exe`
and you might have problems testing it on the automatic flow from Moodle / VMChecker.

1. [Install MinGW](https://www.geeksforgeeks.org/installing-mingw-tools-for-c-c-and-changing-environment-variable/).
Follow all instructions, including adding the app to PATH.
2. Open `C:\MinGW:\bin` folder and locate the `mingw32-make.exe` file and rename
it to `make`.
3. Restart your PowerShell and make sure that environment variables are set
properly.
If they are, the following commands might succeed:
```powershell
gcc --version
make --version
```
4. Install [GIT](https://git-scm.com/downloads/win).

# Linux / WSL2 setup
```bash
sudo apt update
sudo apt install build-essentials
sudo apt install git-all
```

# macOS setup
Open a terminal and check if you have brew installed:
```bash
brew --version
```
If it is not installed, follow [these instructions](https://brew.sh/).

Install GIT:
```
sudo brew update
sudo brew upgrade
sudo brew install git
```

Check if you have GCC installed:
```bash
gcc --version
```
If it is not installed, run the following commands:
```bash
sudo brew update
sudo brew upgrade
sudo brew install gcc
```

Install C dev dependencies:
```bash
xcode-select --install
```


**Congrats! 🎉 🙌🏻**
**Now you are all set to begin your PCLP1 journey 🚀**
