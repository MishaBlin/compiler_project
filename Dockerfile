FROM gcc:latest

RUN apt-get update && apt-get install -y flex

WORKDIR /compiler

COPY . .

RUN chmod +x run.sh

CMD ["/bin/bash"]