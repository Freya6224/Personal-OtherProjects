import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import {loadStripe} from '@stripe/stripe-js';
import { CartService } from 'src/app/Services/cart.service';
import { Cart, CartItem } from 'src/app/models/cart.model';

@Component({
  selector: 'app-cart',
  templateUrl: './cart.component.html',
  styleUrls: ['./cart.component.css']
})
export class CartComponent implements OnInit{
  cart: Cart = {items: [{
    product: 'https://via.placeholder.com/150',
    name: 'snickers',
    price: 150,
    quantity: 1,
    id: 1,
  },
  {
    product: 'https://via.placeholder.com/150',
    name: 'snickers',
    price: 150,
    quantity: 3,
    id: 2,
  }]};
  
  dataSource: Array<CartItem> = [];
  displayedColumns: Array<string> = [
    'product',
    'name',
    'price',
    'quantity',
    'total',
    'action'
  ];
  constructor(private cartService: CartService, private http: HttpClient){}

  ngOnInit(): void {
    this.cartService.cart.subscribe((_cart: Cart) => {this.cart = _cart;
    this.dataSource = this.cart.items;
    });
  }

  getTotal(items: Array<CartItem>):number
  {
    return this.cartService.getTotal(items)

  }

  onClearcart(): void
  {
    this.cartService.clearCart();
  }

  onRemoveFromCart(item: CartItem): void
  {
    this.cartService.removeFromCart(item);
  }

  onRemoveQuantity(item: CartItem): void
  {
    this.cartService.removeQuantity(item);
  }

  onAddQuantity(item: CartItem): void
  {
    this.cartService.addToCart(item);
  }

  onCheckout(): void 
  {
    this.http.post('http://localhost:4242/checkout',{
      items: this.cart.items
    }).subscribe(async(res:any) => {
      let stripe = await loadStripe('pk_test_51NXnOuJFvBslGBQhaOIP0H3zZ4w4hDdADh0jOq6646oAfKD3FuzSLEYLAESqzlklti9JvyUUgtyqamwAGPwvV8zR00LAjuIqBR');
    stripe?.redirectToCheckout({
      sessionId: res.id
    })
    });
  }
}
