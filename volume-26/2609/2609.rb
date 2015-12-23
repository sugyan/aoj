def calc(w, h, v, t, x, y, p, q)
  c = 0
  d = v * t
  (-d / w - 2 .. d / w + 2).each do |i|
    tx = i * w + (i.odd? ? w - p : p)
    next if (tx - x).abs > d
    dy = Math::sqrt(d ** 2 - (tx - x) ** 2);
    next if (q - y).abs > dy
    r = [ (dy + y) / h, -(dy - y) / h - 1 ].map(&:to_i)
    r[1] -= 1 if y > dy
    if r[0] == r[1]
      c += 1 if (tx - x) ** 2 + (q - y) ** 2 <= d * d
    else
      c += r[0] - r[1] - 1;
      r.each do |k|
        ty = k * h + (k.odd? ? h - q : q);
        c += 1 if (tx - x) ** 2 + (ty - y) ** 2 <= d * d
      end
    end
  end
  c
end
1.times do
  w, h, v, t, x, y, p, q = gets.split.map(&:to_i)
  puts calc(w, h, v, t, x, y, p, q)
end
