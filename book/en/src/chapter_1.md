<div align=right>

  🌎 [中文] | [English]
</div>

[中文]: ../chapter_1.html
[English]: ./chapter_1.html

# Tools Installation and Environment Configuration

This chapter introduces how to install the d2x tool, create a template project, and perform basic environment configuration.

## 1. Installing the d2x Tool

### Method 1: Installation via xlings Package Manager (Recommended)

[xlings](https://xlings.d2learn.org) is an open-source package manager that can solve inconsistent dependency issues across different environments.

<details>
  <summary>Click to view xlings installation command</summary>

---

#### Linux/MacOS

```bash
curl -fsSL https://d2learn.org/xlings-install.sh | bash
```

#### Windows - PowerShell

```bash
irm https://d2learn.org/xlings-install.ps1.txt | iex
```

> tips: xlings -> [details](https://xlings.d2learn.org)

---

</details>

```bash
xlings install d2x
```

### Method 2: Building from Source

TODO...

## 2. Creating a Project & Testing

### Creating a Project

**Create via Template (Recommended)**

Click the [Create New Tutorial Template](https://github.com/new?template_name=d2x-project-template&template_owner=d2learn) button to create a new tutorial project from the template repository. Then, clone the generated repository to your local machine.

```bash
git clone git@github.com:your_name/your_repo_name.git
```

**Local Creation**

Create a new project using the `d2x new xxx` command.

```bash
d2x new d2hello
```

After running the command, a directory named `d2hello` will be generated. Enter/open this directory to see the basic structure of the project.

### Testing

Enter the root directory of the newly created project and run commands to test completeness.

**Documentation Preview Command Test**

Running the following command will open the project's documentation/book in your browser.

```bash
d2x book
```

**Code Auto-Detection Function Test**

Running the checker command below will enter the real-time code detection mode in the console. When you modify the file code, the console will update automatically.

```bash
d2x checker
```
