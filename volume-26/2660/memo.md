愚直に動的計画法で出来るのだけど、各分割における計算コストを求めるために各分割点での両側の総和も求めておく必要がある。
計算コストの求め方もちょっと特殊なのでミスらないように慎重に書かないとサンプル入力例も少なくデバッグがしづらい…。

Ruby版はそのまま移植してもコストの計算で時間がかかりすぎて通らなかった。コスト計算する前に検証を行い、それまでの最小値候補を上回ってしまうのが分かっている場合はスキップするようにしてようやくギリギリ収まった。。