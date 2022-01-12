set -x
set -e

export DEBIAN_FRONTEND=noninteractive
apt-get update 
apt-get install -y \
    git \
    gcc \
    make \
    python3 \
    python3-pip \
    ninja-build \
    cmake 
pip install conan