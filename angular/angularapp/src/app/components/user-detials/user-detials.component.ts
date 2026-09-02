import { Component, OnInit } from '@angular/core';
import {Router, ActivatedRoute, Params} from '@angular/router';

@Component({
  selector: 'app-user-detials',
  templateUrl: './user-detials.component.html',
  styleUrls: ['./user-detials.component.css']
})
export class UserDetialsComponent implements OnInit {
  id:number;
  constructor(
    private route:ActivatedRoute,
    private router: Router

  ) { 
    this.route.params.subscribe((params:Params) =>{
      //console.log(params);
      this.id = params.id;
    });
  }

  ngOnInit() {
  }

}
