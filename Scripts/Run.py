#!/usr/bin/env python3

import subprocess
import sys

cmake_files_dir: str = ""


def build(cmd_args: [str]) -> int:
    cmake_args: [str] = ["cmake", "-G", "Ninja"]
    global cmake_files_dir

    if "compiledb=on" in cmd_args:
        print("Compile Commands: on")
        cmake_args.append("-DCMAKE_EXPORT_COMPILE_COMMANDS=ON")

    if "debug=on" in cmd_args:
        print("Debug Symbold: on")
        cmake_args.append("-DCMAKE_BUILD_TYPE=Debug")
        cmake_files_dir = "build/debug"
    else:
        cmake_files_dir = "build/release"

    cmake_args.append(f"-B {cmake_files_dir}")
    result: int = subprocess.run(cmake_args).returncode
    result = subprocess.run(
        ["cmake", "--build", cmake_files_dir, "-j", "14"]).returncode

    return result


def run() -> int:
    global cmake_files_dir

    result: int = subprocess.run(
        [f"{cmake_files_dir}/out/bin/VortexExample"]).returncode

    return result


if "__main__" == __name__:
    cmd_args = sys.argv

    result: int = build(cmd_args)

    if result == 0:
        should_run: bool = True if input(
            "Run program?: y/n ") == "y" else False

        if should_run:
            run()
