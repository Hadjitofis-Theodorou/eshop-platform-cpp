FROM debian:stable-slim


RUN apt-get update && \
    apt-get install -y g++ make cmake && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app


COPY . /app
RUN make clean && make  # Assumes your Makefile produces 'oop24'


RUN mkdir -p files

CMD ["./oop24", "files/categories.txt", "files/products.txt", "files/users.txt"]
