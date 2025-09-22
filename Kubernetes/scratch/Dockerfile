# Build stage
FROM golang:1.24.4 AS build


# run credentials handover for IDULibs Repo
#ARG LIB_DEPLOY_KEY
#
#RUN git config --global url.git@github.com:.insteadOf https://github.com/ && \
#mkdir ~/.ssh
#RUN echo "$LIB_DEPLOY_KEY" > ~/.ssh/id_rsa
#RUN chmod 600 ~/.ssh/id_rsa && \
#echo "Host github.com\n\tStrictHostKeyChecking no\n" >> ~/.ssh/config

# Set working directory
WORKDIR /go/src/app

# pre-copy/cache go.mod
COPY go.mod go.sum
COPY . .
RUN go mod download

RUN CGO_ENABLED=0 go build -o /go/bin/app

FROM debian:stable-slim

COPY --from=build /go/bin/app /
CMD ["/app"]
