"
Copyright (c) 2007-2008 Luca Bruno

This file is part of Smalltalk YX.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the 'Software'), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
"

!Float methodsFor: 'coercing'!

asFraction
    ^self notYetImplemented
!

asFloat
    ^self
!

unity
    ^1.0
!

generality
    ^50
!

zero
    ^0.0
!

coerce: aNumber
    ^aNumber asFloat
! !

!Float methodsFor: 'printing'!

printNl
    ^self print
!

print
    <primitive: 'Float_print'>
	self primitiveFailed
! !

!Float methodsFor: 'testing'!

isFloat
    ^true
! !

!Float methodsFor: 'comparing'!

< aNumber
     <primitive: 'Float_lt'>
	 ^super < aNumber
!

> aNumber
     <primitive: 'Float_gt'>
	 ^super > aNumber
!

<= aNumber
     <primitive: 'Float_le'>
	 ^super <= aNumber
!

>= aNumber
     <primitive: 'Float_ge'>
	 ^super >= aNumber
!

= aNumber
     <primitive: 'Float_eq'>
	 ^super = aNumber
!

== aNumber
     <primitive: 'Float_eq'>
	 ^super == aNumber
!

~= aNumber
     <primitive: 'Float_ne'>
	 ^super ~= aNumber
!

~~ aNumber
     <primitive: 'Float_ne'>
	 ^super ~~ aNumber
! !

!Float methodsFor: 'arithmetic'!

+ aNumber
     <primitive: 'Float_plus'>
	 ^super + aNumber
!

- aNumber
     <primitive: 'Float_minus'>
	 ^super - aNumber
!

* aNumber
     <primitive: 'Float_mul'>
	 ^super * aNumber
!

/ aNumber
     <primitive: 'Float_div'>
         ^super / aNumber
!

\\ aNumber
     self notYetImplemented
! !

!Float methodsFor: 'truncation and round off'!

ceiling
    <primitive: 'Float_ceil'>
	self primitiveFailed
!

floor
    <primitive: 'Float_floor'>
	self primitiveFailed
!

truncated
    <primitive: 'Float_trunc'>
	self primitiveFailed
! !
