import { Component, OnInit } from '@angular/core';
import { OnChanges } from '@angular/core/src/metadata/lifecycle_hooks';
import { DataService} from '../../services/data.service';

import {Question} from '../../Models/Question';

@Component({
  selector: 'app-question-list',
  templateUrl: './question-list.component.html',
  styleUrls: ['./question-list.component.css']
})
export class QuestionListComponent implements OnInit {
  questions:Question[];

  constructor(public dataservice:DataService) { 

  }

  ngOnInit() {
    this.questions = this.dataservice.getQuestion();
  }

  addQuestion(question:Question) {
    this.dataservice.addQuestion(question);
  }
}
