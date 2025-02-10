// Unity에서 글자를 깜빡거리게 할 때, 혹은 컷씬 장면 전환을 위해 사용함

IEnumerator Fadeout() // 페이드아웃
    {
        float alpha = 0;
        while (alpha < 0.8f)
        {
            alpha += 0.005f;
            image.color = new Color(0, 0, 0, alpha);
            yield return null;
        }
            text.gameObject.SetActive(true);  // 패널값을 조정할 텍스트
            StartCoroutine(FadeTextToFull()); // 텍스트 깜빡거리기

    }



    public IEnumerator FadeTextToFull() // 알파값 0에서 1로 전환
    {
        text.color = new Color(text.color.r, text.color.g, text.color.b, 0);
        while (text.color.a < 1.0f)
        {
            text.color = new Color(text.color.r, text.color.g, text.color.b, text.color.a + 0.02f);
            yield return new WaitForSeconds(0.1f);
        }
        StartCoroutine(FadeTextToZero());
    }

    public IEnumerator FadeTextToZero()  // 알파값 1에서 0으로 전환
    {
        text.color = new Color(text.color.r, text.color.g, text.color.b, 1);
        while (text.color.a > 0.0f)
        {
            text.color = new Color(text.color.r, text.color.g, text.color.b, text.color.a - 0.02f);
            yield return new WaitForSeconds(0.1f);
        }
        StartCoroutine(FadeTextToFull());
    }


// 이렇게 하면 FadeTextToFull()에서 FadeTextToZero()으로 계속 왔다갔다 하게 됨.
 
 
 
IEnumerator FadeIn() // 추가적으로 페이드 인
    {
        float alpha = 1.0f;
        while (alpha > 0.0f)
        {
            alpha -= 0.03f;
            image.color = new Color(0, 0, 0, alpha);
            yield return null;
        }
        image.gameObject.SetActive(false);
    }
