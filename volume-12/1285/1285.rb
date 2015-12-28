def calc(n, w, v)
  r = [0] * 100
  v.each do |e|
    r[e / w] += 1
  end
  r.map.with_index do |e, i|
    e.to_f / r.max * (v.max / w - i) / (v.max / w)
  end.inject(:+) + 0.01
end
loop do
  n, w = gets.split.map(&:to_i)
  break if n == 0
  v = []
  n.times do |i|
    v[i] = gets.to_i
  end
  puts calc(n, w, v)
end
