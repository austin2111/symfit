#!/bin/sh
set -e

git clone https://github.com/bitsecurerlab/symcc.git
#git clone --branch softmmu_demo https://github.com/austin2111/symfit.git # No need to clone twice...
git clone --branch softmmu_json_demo https://github.com/austin2111/symsan.git

git -C ./symcc submodule update --init --recursive

git config --global --add safe.directory '*'
# Making all directories safe in a docker container should be fine. On fundamental principle,
# this should probably be more restrictive though.

mkdir symcc_build symsan_build symfit_symsan_build

./compile.sh --symcc
./compile.sh --symsan
./compile.sh --symfit_symsan

echo "Installing patched symcc_fuzzing_helper utility..."

patch /workdir/symcc/util/symcc_fuzzing_helper/src/main.rs /workdir/symfit/symcc_helper.patch
cargo build --manifest-path /workdir/symcc/util/symcc_fuzzing_helper/Cargo.toml --target-dir /workdir/symcc/util/symcc_fuzzing_helper
cp /workdir/symcc/util/symcc_fuzzing_helper/debug/symcc_fuzzing_helper /workdir/

echo "Installation complete! In the future, please run launch.sh before entering the Symfit environment. To get started, try running an emulator boot script."
