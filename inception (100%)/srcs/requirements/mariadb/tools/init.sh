#!/bin/sh

# Start MariaDB server
mysqld_safe &

# Wait for MariaDB to start
until mysqladmin ping >/dev/null 2>&1; do
    sleep 1
done

# Create database and user
mysql -u root << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

# Keep container running
tail -f /dev/null 