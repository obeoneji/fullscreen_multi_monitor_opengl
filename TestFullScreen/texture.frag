sampler2D myTexture;
varying vec2 vTexCoord;

void main (void)  
{  
   vec4 color = texture2D(myTexture, vTexCoord);        
   
   gl_FragColor = color;
	gl_FragColor = texture2D(myTexture, vTexCoord).rgba;
}    
