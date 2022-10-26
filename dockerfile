FROM gcc:11.3
RUN apt update && apt install -y lcov cmake
