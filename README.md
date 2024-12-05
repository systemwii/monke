# monke

*when lost in the c, all i crave is a return to monke*

In the realm of Wii/GameCube programming with DevkitPPC and libogc, **monke** is a kind of standard library that provides simple interfaces for handling common tasks. Things that are usually copy-pasted around projects, but provided in a unified framework that can be automatically included in projects, with updating or fixing a given version. It's meant to make basic tasks intuitively approachable for the inexperienced, so they can not worry about their implementations and be confident in their correctness.

```bash
git submodule add https://github.com/systemwii/monke.git lib/monke
cd lib/monke && git checkout [branch/tag/commit] && ../..
```

You can, of course, also just copy-paste the files :p but you'd be opting out of easy updating and separating boilerplate code out of your main Git repo.

For simplicity, monke is intended to be included as source on a per-folder basis rather than as a library, so you would add its folders to your Makefile individually as:

```makefile
SRCS    :=  lib/monke/console
```

Again, you can also just copy-paste into your primary source directory, if you don't mind mixing up the files.

monke is a project that strives towards best-practice code for general cases, which should ideally only need to be deviated from in projects if they have special requirements. It has a _snippets folder for code that isn't ready to be packaged as includable source code, but shows off some sort of recommended practice. And this repo is meant to promote discussion about such practices – how to do things best 👍.

*homebrew devs on monke: [(link)](https://www.tiktok.com/@mewtru/video/7441327012045720874)*

## Folders

* **console**: basic terminal
* **sha1**: hashing algorithm used by the Wii
