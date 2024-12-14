import { Component, EventEmitter, OnInit, Output } from '@angular/core';

@Component({
  selector: 'app-products-header',
  templateUrl: './products-header.component.html',
  styleUrls: ['./products-header.component.css']
})
export class ProductsHeaderComponent implements OnInit{

  @Output() columnsCountChange = new EventEmitter<number>();
  @Output() itemCountChange = new EventEmitter<number>();
  @Output() sortChange = new EventEmitter<string>();

  sort = 'desc';
  itemsShowCount = 12;

  constructor() {}

  ngOnInit(): void {
    
  }

  onSortUpadted(newSort: string ): void
  {
    this.sort = newSort;
    this.sortChange.emit(newSort);
  }

  onItemsUpadted(count: number ): void
  {
    this.itemsShowCount = count;
    this.itemCountChange.emit(count);
  }



  onColumnsUpadted(colsNum: number):void
    {
      this.columnsCountChange.emit(colsNum);
    }

}
