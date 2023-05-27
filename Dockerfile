FROM debian:latest

WORKDIR /app/root

RUN git clone https://github.com/bbzblit/stundenplan-api.git .

RUN apt-get update && apt-get install curl sudo -y \
    && curl -sS https://downloads.mariadb.com/MariaDB/mariadb_repo_setup | sudo bash\
    && apt update && apt install -y libjsoncpp24  libjsoncpp-dev  libmariadbclient18  libmariadbclient-dev  mariadb-client libmariadb-dev\
    && sudo apt install git gcc g++ cmake libjsoncpp-dev uuid-dev openssl libssl-dev zlib1g-dev -y \
    && cd /tmp \
    && git clone https://github.com/an-tao/drogon \
    && cd drogon \
    && git submodule update --init \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make && sudo make install \
    && cd /app/root \
    && rm -rf build \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make

ENTRYPOINT ["/app/root/build/stundenplan_api"]
