def calc(f, q, w, h)
  n = 0
  while q.size > 0
    n += 1
    p = q.shift
    [[-1, 0], [0, -1], [0, 1], [1, 0]].each do |d|
      i, j = p[0] + d[0], p[1] + d[1]
      if i >= 0 && i < h && j >= 0 && j < w && f[i][j] == '.'
        f[i][j] = '#'
        q.push([i, j])
      end
    end
  end
  n
end
loop do
  f, q = [], []
  w, h = gets.split.map(&:to_i)
  break if w + h == 0
  h.times do |i|
    f[i] = gets.chomp.split('')
    j = f[i].index('@')
    q[0] = [i, j] if j
  end
  puts calc(f, q, w, h)
end
