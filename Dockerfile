FROM centos
COPY lab3.cpp .
RUN yum install gcc -y
RUN yum install gcc-c++ -y
RUN gcc lab3.cpp -o exe
CMD ./exe
