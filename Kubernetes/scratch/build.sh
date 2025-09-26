#!/bin/bash

# eval to minukube, making this very specific and that makes me sad
eval $(minikube -p minikube docker-env)

# run rebuild and also restart deployment, just for testing and debugging, not production safe!
docker build --build-arg LIB_DEPLOY_KEY="$GIT_IDULIB_LOCAL" -t i_scratch_go . && k rollout restart deployment scratch
