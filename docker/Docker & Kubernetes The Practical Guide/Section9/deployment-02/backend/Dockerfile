FROM node

WORKDIR /app

COPY package.json .

RUN npm install

COPY . .

EXPOSE 80

ENV MONGODB_USERNAME=gene
ENV MONGODB_PASSWORD=nomads
ENV MONGODB_URL=cluster0.s99rm.mongodb.net
ENV MONGODB_NAME=goals-dev

CMD ["npm", "start"]