#lang racket
; Programming Exercise 3
; Kyle Senoy and Justin Veloso C-1L
; Function A - Factorial of N

(define (factorial n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(define (main)
  (define n 124)  
  (displayln (string-append "Factorial of " (number->string n) " is " (number->string (factorial n))))) 

(main)
