<div align=right>

  🌎 [中文] | [English]
</div>

[中文]: ../chapter_2.html
[English]: ./chapter_2.html

# Project Configuration and Adding New Content

This chapter mainly introduces the basic structure of the template project, and how to configure and add your own content based on the template.

## 1. Understanding Project Structure

d2x-type projects are interactive tutorial projects, usually consisting of `[Book + Video + Code + X]` four parts:

- `Book`: Tutorial documentation or e-book
- `Video`: Corresponding project tutorial videos
- `Code`: Corresponding interactive practice code collection
- `X`: Custom support and services provided by project authors, such as forums, chat groups, etc.

Among these, `Book` and `Code` are essential, while `Video` and `X` can be adjusted according to creation needs.

From the perspective of project directory structure, their relationships are as follows:

```cpp
.
├── book                   ////// Book: Documentation/Book directory
│   ├── book.toml            // Book configuration file
│   └── src                  // Book/Documentation Markdown source directory
│       ├── chapter_0.md
│       ├── chapter_1.md     // Book/Documentation Markdown source
│       ├── chapter_2.md
│       ├── chapter_3.md
│       └── SUMMARY.md       // Book table of contents
├── config.xlings
├── d2x
├── dslings                ////// Code: Project practice code directory
│   ├── hellomcpp.cpp        // Specific practice code
│   ├── hellocpp.cpp       
│   └── xmake.lua            // Practice code arrangement and configuration file
├── LICENSE
├── README.md
├── videos                 ////// Video: Project tutorial video (materials) directory
└── xmake.lua
```

## 2. Book: Writing Tutorials/Books - Adding New Chapters

### Starting Documentation/Book Preview

Run the following command in the project directory to enter real-time book preview mode:

```bash
d2x book
```

### Modifying Basic Book Configuration

**Book Title**

Edit the `title` in the `book/book.toml` file to give your project book a name.

Before modification:

```toml
[book]
authors = ["sunrisepeak"]
language = "en"
multilingual = false
src = "src"
title = "D2X Project Template | D2X项目模板" <-- Modification location
```

After modification:

```toml
[book]
authors = ["sunrisepeak"]
language = "en"
multilingual = false
src = "src"
title = "Build XXX from Scratch"
```

You can see the book title changed to "Build XXX from Scratch" in your browser.

**Adding Github Repository Link (Optional)**

Add the Github repository link to the property below:

```toml
[output.html]
git-repository-url = "xxxx"
```

### Modifying Book Table of Contents

Edit the `book/src/SUMMARY.md` file to adjust the table of contents display.

Before modification:

```markdown
# Summary

- [Introduction](./chapter_0.md)
- [Tools Installation and Environment Configuration](./chapter_1.md)
- [Project Configuration and Adding Content](./chapter_2.md)
- [Waiting for Your Extension](./chapter_3.md) <-- Modification location
```

After modification:

```markdown
# Summary

- [Introduction](./chapter_0.md)
- [Tools Installation and Environment Configuration](./chapter_1.md)
- [Project Configuration and Adding Content](./chapter_2.md)
- [My New Chapter](./chapter_3.md)
```

Renamed Chapter 4 to "My New Chapter".

### Modifying Chapter Content and Adding New Chapters

Edit the file corresponding to the title, such as for `- [My New Chapter](./chapter_3.md)`, the corresponding file is `book/src/chapter_3.md`. Changes can be observed in the preview.

Adding new chapters:

- Step 1: Add chapter file in the `book/src` directory and fill in the content
- Step 2: Add the file's table of contents index in `book/src/SUMMARY.md`

> Note: For more configuration details, refer to [mdbook documentation](https://rust-lang.github.io/mdBook)

## 3. Code: Adding New Practice Code

The project's practice code is centralized in the `dslings` directory. When users run the `d2x checker` command, it automatically loads these practice codes into a detection queue and jumps to the first practice code with detection differences, waiting for the user to modify and complete it.

The d2x tool monitors real-time file changes in practice code. When users modify the code, it automatically triggers the detection program. If the detection passes, it automatically jumps to the next exercise; if not, it outputs error messages in the console.

Detection types are divided into two categories:

- `Compilation-time checking`: Checks if the practice code can compile normally
- `Runtime checking`: After code compilation checking passes, it verifies whether the execution meets requirements

### Experiencing Automatic Code Practice Detection Program

The project provides code practice examples by default, which can be experienced by running the following command:

```bash
d2x checker
```

Fix the code according to the console error messages and observe changes in the console. Below is an explanation of the console information:

```
 🌏 ▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 0/2  -->> Display current exercise progress
                                                                                                                               
 ✗ hellocpp                 -->> Current detection status and exercise name
 + → dslings/hellocpp.cpp   -->> Current exercise file path
                                                                                                                               
 [ 23%]: cache compiling.release dslings/hellocpp.cpp -->> Display compilation status
 error: dslings/hellocpp.cpp:29:39: error: found ':' in nested-name-specifier, expected '::'
    29 |     std::cout << "hello, mcpp!" << std:endl; // 0. Fix this compilation error
       |                                       ^
       |                                       ::
   ▼ 5 more lines below...

🤖:   AI Disabled - https://github.com/d2learn/d2x  -->> Display AI status/information (requires configuring large model keys, optional)
```

> Note: Use `Ctrl + C` to exit the detection program

### Adding New Practice Code & Verification

- Step 1: Add practice code file
- Step 2: Add the practice code file to the practice configuration file

**Practice Code File - 0-test.cpp**

Create a `0-test.cpp` file in the `dslings` directory and add the following content:

```cpp
#include <d2x/cpp/d2x.hpp> // Auxiliary tools

#include <iosteam> // Intentionally misspelled for testing compilation-time checking

int main() {
    std::cout << "Hello World ..." << std::endl;

    int a = 1;
    int b = 2;

    d2x::assert_eq(a, b); // Test runtime checking
}
```

**Add 0-test.cpp to the Practice Configuration File**

Add basic information about `0-test.cpp` to the `dslings/xmake.lua` file:

```lua
target("0-test")
    add_files("0-test.cpp")
```

**Re-run the Detection Program for Verification**

Run `d2x checker` again in the project root directory to observe the console and see if the new practice code was loaded.

Modify the errors in the practice code and observe the console changes.

### Practice Code Design

Automated code practice projects supported by the d2x tool, by running `d2x checker` in the project root directory, enter "compiler-driven development mode" for automatic practice code detection. Users need to modify code errors based on console error messages and hints. After fixing all compilation errors and runtime checkpoints, you can delete or comment out `d2x::wait()` in the code to automatically proceed to the next exercise.

- `d2x::wait()`: Used to isolate different exercises. You can delete or comment it out to proceed to the next exercise.
- `d2x::assert_eq`: Used for runtime checkpoints. You need to fix code errors to pass all checkpoints.
- `D2X_YOUR_ANSWER`: Used to prompt you to modify the code, generally for code completion (replace it with the correct code).

## Other Features (Optional)

### Configuring AI Smart Hint Assistance

The d2x tool provides an AI assistant function during the practice code detection process. This assistant will provide some hints in a humorous way based on current practice code requirements and user intentions.

Edit the `.d2x.json` file in the project directory and configure the LLM to automatically enable this feature:

```json
{
    "buildtools": "xmake d2x-buildtools",
    "lang": "en",
    "llm": {
        "api_key": "",
        "api_url": "https://api.deepseek.com/v1",
        "model": "deepseek-chat",
        "system_prompt": ""
    },
    "ui_backend": "tui"
}
```

The main configuration is for `api_key`, `api_url`, and `model` properties. The above defaults provide DeepSeek configuration. If you have a DeepSeek key, just fill in the `api_key` to use it.

### Configuring Online E-book

The template project provides automatic deployment to Github Pages by default. You just need to enable it:

Specific steps: `Repository Settings -> Pages -> Build and deployment -> Source -> Github Actions`
