FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

# Create directories for MariaDB
RUN mkdir -p /var/lib/mysql && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld

# Initialize MariaDB
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Copy initialization script
COPY tools/init.sh /docker-entrypoint-initdb.d/
RUN chmod +x /docker-entrypoint-initdb.d/init.sh

# Expose port 3306
EXPOSE 3306

# Start MariaDB
CMD ["mysqld", "--user=mysql"] 