#base image
FROM node

ARG APPLICATION_DIR=/app

# where to execute from
# i.e. RUN ... will run in /WORKDIR
# applies to COPY command aswell
# sets operations relative to this dir
WORKDIR ${APPLICATION_DIR}

COPY package.json ${APPLICATION_DIR}

# this is fine since this BUILDS dependencies
# as in build everything this lil fella will need to later be executed
RUN npm install

# 2 paths, 
# from: 1st path outside container (. same folder),
# to: 2nd path inside image, where it should be stored (internal file system)
# . . is just a 1:1 
COPY . ${APPLICATION_DIR}

# don't want to do this since, these are image commands
# as in its not "run this when awake" stuff
# so this would try to run a server on building the image which is rong and dumb
# RUN node server.js

# doesn't actaully expose the port -_-
EXPOSE 80 

# THIS runs when a container is started, not when an image is built
CMD ["node", "server.js"]