FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install -y nginx openssl gettext-base

RUN mkdir -p /etc/nginx/certs

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/nginx/certs/key-selfsigned.key \
-out /etc/nginx/certs/cert-selfsigned.crt \
-subj "/C=FR/ST=North/L=Paris/O=Entropy/OU=Entropy/CN=bdenfir.42.fr"

COPY conf/nginx.conf ./tmp/nginx.conf

RUN envsubst '/etc/nginx/certs key-selfsigned.key cert-selfsigned.crt bdenfir.42.fr' < /tmp/nginx.conf > /etc/nginx/sites-available/default

ENTRYPOINT ["nginx", "-g", "daemon off;"]
