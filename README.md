

# Proof of work test

A proof of work is a piece of data which is difficult (costly, time-consuming) to produce but easy for others to verify and which satisfies certain requirements [[1]] (https://en.bitcoin.it/wiki/Proof_of_work).  This test looks for the first _n_ bits with zero at the beginning of a sha256 hash generated with a random sequence.

## Results

Bits | Hash | Time( s) | Sequence
-----------|---------|--------------|---------------
25 | 00000044194edf481fd55eba5c4a59fe09d31b7b6606526dd302b2db170b7ee6|1.188971|241848
26 | 000000368a10eb45f6a13eb44051909afe21b82843f29da747e0615751824591 | 441.037800 | 97589887
27 | 0000001f7748ebe95ef5b9fea53df335f6b6f1192d2e9e4c50284fc3b6d2a31d | 496.076286 | 110533342
28 | 000000072dbfb118b0bd850ee62f5fdde09465ebedd9db427c7ff3f7ffbce38b | 964.554885 | 229136723
29 | 000000070da08d4e90f357a97c5722faf09474db197736e2974f4041e1ca87fa | 2200.315876 | 566255117

##  Hardware

* SO: ArchLinux
* CPU: Core i7 2.80GHz x4
* RAM: 16 GB