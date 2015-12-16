def calc(c, q, h, w)
  n = 0
  while q.size > 0
    e = q.shift
    n += 1 if e[0] > n
    (-1..1).each do |di|
      (-1..1).each do |dj|
        i = e[1][0] + di
        j = e[1][1] + dj
        if i >= 0 && i < h && j >= 0 && j < w
          q.push([e[0] + 1, [i, j]]) if (c[i][j] -= 1) == 0
        end
      end
    end
  end
  n
end
1.times do
  c, q = [], []
  h, w = gets.split.map(&:to_i)
  h.times do |i|
    c[i] = gets.chomp.split(//).map(&:to_i)
    c[i].each.with_index do |e, j|
      q.push([0, [i, j]]) if c[i][j] == 0
    end
  end
  puts calc(c, q, h, w)
end
