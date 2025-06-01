uniform sampler2D sceneTexture;
uniform sampler2D bloomTexture;
uniform float bloomIntensity;

void main() {
    vec4 scene = texture2D(sceneTexture, gl_TexCoord[0].xy).rgba;
    vec4 bloom = texture2D(bloomTexture, gl_TexCoord[0].xy).rgba;

    gl_FragColor = scene + bloom * bloomIntensity;
}
