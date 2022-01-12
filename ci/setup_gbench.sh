set -x
set -e

git clone https://github.com/google/benchmark.git || true
cd benchmark
cmake -E make_directory "build"
cmake -S ${PWD} -B "build" \
    -DBENCHMARK_DOWNLOAD_DEPENDENCIES=True \
    -DCMAKE_BUILD_TYPE=Release 
cmake --build "build" --config Release -j $(nproc)
