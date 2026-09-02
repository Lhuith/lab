import { Injectable } from '@angular/core';
import {Question} from '../models/Question';

@Injectable()
export class DataService {
questions: Question[];

  constructor() { 
    /*
  this.questions = [
    {
      text:'What is your Name?',
      answer:"My Name is Eugene",
      hide: true
    },
    {
      text:'What is your Favorite Color?',
      answer:"My favorite color is light blue",
      hide: true
    },
    {
      text:'What is your favorite language?',
      answer:"My favorite langage is HLSL",
      hide: true
    },
    {
      text:'What is your favorite Taco?',
      answer:"I dont Like Tacos",
      hide: true
    }
  ];
  */
}

//Get Questions from LS
getQuestion(){
  if(localStorage.getItem('questions') == null){
    this.questions = [];
  }else{
    this.questions = JSON.parse(localStorage.getItem('questions'));
  }


  return this.questions;
}

//Add Question to LS
addQuestion(question:Question){
  this.questions.unshift(question);

  //Init local var
  let questions;

  if(localStorage.getItem('questions') == null){
    questions = [];
    //Push new Question
    questions.unshift(question);
    //Set new Array to local storage
    localStorage.setItem('questions', JSON.stringify(questions));
  }else{
    questions = JSON.parse(localStorage.getItem('questions'));
    //Add new question
    questions.unshift(question);  

    //Reset LS
    localStorage.setItem('questions', JSON.stringify(questions));
  }

}

//Remove Question to LS
removeQuestion(question:Question){
  for(let i = 0; i < this.questions.length; i++) {
    if(question == this.questions[i]){
      this.questions.splice(i, 1);
      localStorage.setItem('questions', JSON.stringify(this.questions));
    }
  }
}

}
