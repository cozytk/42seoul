minikube start --driver=virtualbox
eval $(minikube -p minikube docker-env)

kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

cd srcs
docker build -t nginx-image nginx  
docker build -t ftps-image ftps
docker build -t mysql-image mysql
docker build -t phpmyadmin-image phpmyadmin
docker build -t wordpress-image wordpress
docker build -t influxdb-image influxdb
docker build -t telegraf-image telegraf
docker build -t grafana-image grafana
kubectl apply -f yaml
minikube dashboard
