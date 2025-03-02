#lang racket
; Programming Exercise 3
; Kyle Senoy and Justin Veloso C-1L
; Function C - Sum of Primes

(define (is-prime num div)
  (cond
    [(<= num 1) #f] ; false if num is less than or equal to 1
    [(= div 1) #t] ; prime if it reaches 1
    [(zero? (remainder num div)) #f] ; not prime if divisibile by div
    [else (is-prime num (- div 1))]))

(define (Sumprimes n)
  (define (temp current sum)
    (if (> current n)
        sum
        (temp (+ current 1) (if (is-prime current (- current 1)) (+ sum current) sum))))
  (temp 2 0)) ; start checking at 2 and set the sum to 0

(define (main)
  (display "Enter a number: ")
  (define n (string->number (read-line)))
  (if (number? n)
      (displayln (string-append "Sum of primes from 1 to " (number->string n) " is " (number->string (Sumprimes n))))
      (displayln "Invalid input!")))

(main)