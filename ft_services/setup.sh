echo "***** 1/13 [minikube 시작] *****"
minikube start --driver=virtualbox
eval $(minikube -p minikube docker-env)

echo "***** 2/13 [ARP Mode 설정] *****" 
kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl diff -f - -n kube-system
kubectl get configmap kube-proxy -n kube-system -o yaml | sed -e "s/strictARP: false/strictARP: true/" | kubectl apply -f - -n kube-system
# ARP MODE : 기본적으로 Enable 상태 (ARP패킷을 받아들이고, ARP 테이블에 추가한다.)
# 만약 Disable 상태라면? 라우터는 클라이언트로부터 받은 ARP 요청에 대해 응답하지 않는다. 
# 클라이언트가 통신을 원한다면 수동으로 arp 항목을 추가해야 한다. 
# 예를 들어, 윈도우 클라이언트에서는 arp 커맨드를 사용해서 라우터의 IP와 맥주소를 추가해야한다.

echo "***** 3/13 [matalLB 설치] *****"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

echo "***** 4/13 [matalLB 세팅] *****"
cd srcs/metallb
kubectl apply -f metallb.yaml

echo "***** 5/13 [nginx 이미지 빌드, 셋팅] *****"
cd ../nginx/
docker build -t nginx-image .
kubectl apply -f nginx.yaml

echo "***** 6/13 [ftps 이미지 빌드, 셋팅] *****"
cd ../ftps/
docker build -t ftps-image .
kubectl apply -f ftps.yaml

echo "***** 7/13 [mysql 이미지 빌드, 셋팅] *****"
cd ../mysql
docker build -t mysql-image .
kubectl apply -f mysql.yaml

echo "***** 8/13 [phpmyadmin 이미지 빌드, 셋팅] *****"
cd ../phpmyadmin
docker build -t phpmyadmin-image .
kubectl apply -f phpmyadmin.yaml

echo "***** 9/13 [wordpress 이미지 빌드, 셋팅] *****"
cd ../wordpress
docker build -t wordpress-image .
kubectl apply -f wordpress.yaml

echo "***** 10/13 [influxdb 이미지 빌드, 셋팅] *****"
cd ../influxdb
docker build -t influxdb-image .
kubectl apply -f influxdb_config.yaml
kubectl apply -f influxdb.yaml
# influxdb ? 시계열 데이터를 저장하는 데이터베이스

echo "***** 11/13 [telegraf 이미지 빌드, 셋팅] *****"
cd ../telegraf
docker build -t telegraf-image .
kubectl apply -f telegraf_config.yaml
kubectl apply -f telegraf.yaml
# telegraf ? 시스템 모니터링 및 지표 데이터 수집 agent

echo "***** 12/13 [grafana 이미지 빌드, 셋팅] *****"
cd ../grafana
docker build -t grafana-image .
kubectl apply -f grafana_config.yaml
kubectl apply -f grafana.yaml
# grafana ? 수집(telegraf)하고 저장(influxdb)한 시계열 데이터를 대시보드에서 시각화된 모습으로 수 있다.

echo "***** 13/13 [쿠버네티스 대쉬보드 실행] *****"
minikube dashboard
