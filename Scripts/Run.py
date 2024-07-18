#!/usr/bin/env python3

import subprocess
import sys


def build(cmd_args: [str]) -> int:
    cmake_args: [str] = ["cmake", "-B", "build/", "-G", "Ninja"]

    if "compiledb=on" in cmd_args:
        print("Compile Commands: on")
        cmake_args.append("-DCMAKE_EXPORT_COMPILE_COMMANDS=ON")

    result: int = subprocess.run(cmake_args).returncode
    result: int = subprocess.run(["cmake", "--build", "build/"]).returncode

    return result


def run() -> int:
    result: int = subprocess.run(["build/out/bin/VortexExample"]).returncode

    return result


if "__main__" == __name__:
    cmd_args = sys.argv

    build(cmd_args)

    should_run: bool = True if input("Run program?: y/n ") == "y" else False

    if should_run:
        run()
