uniform sampler2D texture;
uniform vec2 direction;

void main() {
    vec2 texCoord = gl_TexCoord[0].xy;
    vec4 result = vec4(0.0);
    float base = 0.5;
    float weights[25];
    int i;

    i = 0;
    while (i < 25) {
        weights[i] = base;
        base -= 0.01f;
        i++;
    }
    for (int i = -24; i <= 24; i++) {
        int index = abs(i);
        vec2 offset = float(i) * direction / 4;
        result += texture2D(texture, texCoord + offset) * weights[index];
    }
    gl_FragColor = result;
}
