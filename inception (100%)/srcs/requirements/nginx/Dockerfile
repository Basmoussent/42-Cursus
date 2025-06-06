FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Create directory for SSL certificates and nginx sites
RUN mkdir -p /etc/nginx/ssl && \
    mkdir -p /etc/nginx/sites-available

# Generate SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/nginx/ssl/nginx.key \
-out /etc/nginx/ssl/nginx.crt \
-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=basmoussent.42.fr"

COPY ./tools/copy.sh /copy.sh
RUN chmod +x /copy.sh

CMD ["/bin/sh", "/copy.sh"]
