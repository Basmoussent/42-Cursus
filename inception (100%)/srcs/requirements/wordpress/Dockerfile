FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-common \
    php-curl \
    php-zip \
    php-xml \
    php-mbstring \
    php-gd \
    php-intl \
    wget \
    unzip \
    && rm -rf /var/lib/apt/lists/*

# Create directory for WordPress
RUN mkdir -p /var/www/html

# Download and install WordPress
RUN wget https://wordpress.org/latest.zip && \
    unzip latest.zip && \
    mv wordpress/* /var/www/html/ && \
    rm -rf wordpress latest.zip

# Configure PHP-FPM
RUN sed -i 's/listen = 127.0.0.1:9000/listen = 9000/g' /etc/php/8.2/fpm/pool.d/www.conf

# Set permissions
RUN chown -R www-data:www-data /var/www/html

# Expose port 9000
EXPOSE 9000

# Start PHP-FPM
CMD ["php-fpm8.2", "-F"] 