def calc(t, s)
  tones = %w(C C# D D# E F F# G G# A A# B)
  [1, 2].each{|j|
    i = t.size - j
    s.reverse.each{|e|
      idx = tones.index(e)
      if tones.index(t[i]) == idx
        i -= 1
      elsif (tones.index(t[i]) - 1) % 12 == idx && i < t.size - 1
        i += 1
      elsif (tones.index(t[i]) + 1) % 12 == idx && i > 0
        i -= 2
      else
        break
      end
      return 'Yes' if i == -1
    }
  }
  'No'
end
gets.to_i.times do
  gets
  t = gets.chomp.split
  s = gets.chomp.split
  puts calc(t, s)
end
