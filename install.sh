#!/bin/sh
set -e

if ! docker ps >/dev/null 2>&1; then
    echo "Error: Cannot run Docker commands."
    echo "Please either:"
    echo "  1. Run this script with sudo"
    echo "  2. Add your user to the docker group: sudo usermod -aG docker $USER"
    echo "     (then log out and back in)"
    exit 1
fi

# Run this first for fresh pull!

cp run/*.sh ../ # Stick all the scripts in the root directory
cd ../ # Go to said root directory before compiling

echo "Pulling SymFit Docker environment..."
echo "Note: You must be logged into Docker CLI to pull the image"

# Please be aware that you will need to be logged into the Docker CLI tool to pull the Symfit docker image
#docker pull ghcr.io/bitsecurerlab/symfit:latest

if ! docker pull ghcr.io/bitsecurerlab/symfit:latest; then
    echo "Error: Failed to pull Docker image."
    echo "Please check:"
    echo "  1. You are logged into Docker (docker login ghcr.io)"
    echo "  2. You have access to the repository"
    echo "  3. Your network connection is working"
    exit 1
fi

docker run --rm -ti --ulimit core=0 \
            -v $PWD:/workdir        \
            symfit_env /bin/bash -c "/workdir/install_pt2.sh && /bin/bash"

