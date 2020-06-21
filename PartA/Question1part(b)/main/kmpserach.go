package main

import "fmt"

func main() {

	text := "fastnuces"
	pattren := "fast"
	KMPSearch(text, pattren)
}

func KMPSearch(text string, pat string) {
	M := len(pat)
	N := len(text)

	for index := 0; index < M-N; index++ {

		for indexj := 0; indexj < M; indexj++ {
			if text[index+indexj] != pat[indexj] {
				break
			}

			if index == indexj {
				fmt.Println("we have found substring at index=", index)
			}

		}

	}

}
