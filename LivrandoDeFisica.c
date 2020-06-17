#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct grandeza{
    float v;
    float dlt;
} grandeza;

float modulo (float x)
{
    if (x<0) return -x;
    else return x;
}

void parametros_iniciais (grandeza *m1, grandeza *m2, grandeza *l1, grandeza *l2, grandeza *t1, grandeza *t2)
{
    grandeza l1_aux, l2_aux, m1_aux, m2_aux, t1_aux, t2_aux;

    printf ("Digite o valor do comprimento l1: ");
    scanf ("%f",&l1_aux.v);
    printf ("Digite o valor do delta do comprimento l1: ");
    scanf ("%f",&l1_aux.dlt);

    printf ("Digite o valor do comprimento l2: ");
    scanf ("%f",&l2_aux.v);
    printf ("Digite o valor do delta do comprimento l2: ");
    scanf ("%f",&l2_aux.dlt);

    printf ("Digite o valor de massa m1: ");
    scanf ("%f",&m1_aux.v);
    printf ("Digite o valor do delta da massa m1: ");
    scanf ("%f",&m1_aux.dlt);

    printf ("Digite o valor de massa m2: ");
    scanf ("%f",&m2_aux.v);
    printf ("Digite o valor do delta da massa m2: ");
    scanf ("%f",&m2_aux.dlt);

    printf ("Digite o valor do tempo t1: ");
    scanf ("%f",&t1_aux.v);
    printf ("Digite o valor do delta do tempo t1: ");
    scanf ("%f",&t1_aux.dlt);

    printf ("Digite o valor do tempo t2: ");
    scanf ("%f",&t2_aux.v);
    printf ("Digite o valor do delta do tempo t2: ");
    scanf ("%f",&t2_aux.dlt);

    m1->v=m1_aux.v;
    m1->dlt=m1_aux.dlt;
    m2->v=m2_aux.v;
    m2->dlt=m2_aux.dlt;

    l1->v=l1_aux.v;
    l1->dlt=l1_aux.dlt;
    l2->v=l2_aux.v;
    l2->dlt=l2_aux.dlt;

    t1->v=t1_aux.v;
    t1->dlt=t1_aux.dlt;
    t2->v=t2_aux.v;
    t2->dlt=t2_aux.dlt;

}

void parametros_iniciais2 (grandeza *m1, grandeza *m2, grandeza *l1, grandeza *l2, grandeza *t1, grandeza *t2, grandeza *m2_p)
{
    grandeza l1_aux, l2_aux, m1_aux, m2_aux, t1_aux, t2_aux, m2_p_aux;

    printf ("Digite o valor do comprimento l inicial: ");
    scanf ("%f",&l1_aux.v);
    printf ("Digite o valor do delta do comprimento li: ");
    scanf ("%f",&l1_aux.dlt);

    printf ("Digite o valor do comprimento l final: ");
    scanf ("%f",&l2_aux.v);
    printf ("Digite o valor do delta do comprimento lf: ");
    scanf ("%f",&l2_aux.dlt);

    printf ("Digite o valor de massa m inicial: ");
    scanf ("%f",&m1_aux.v);
    printf ("Digite o valor do delta da massa mi: ");
    scanf ("%f",&m1_aux.dlt);

    printf ("Digite o valor de massa m final: ");
    scanf ("%f",&m2_aux.v);
    printf ("Digite o valor do delta da massa mf: ");
    scanf ("%f",&m2_aux.dlt);

    printf ("Digite o valor de massa m2: ");
    scanf ("%f",&m2_p_aux.v);
    printf ("Digite o valor do delta da massa m2: ");
    scanf ("%f",&m2_p_aux.dlt);

    printf ("Digite o valor do tempo t inicial: ");
    scanf ("%f",&t1_aux.v);
    printf ("Digite o valor do delta do tempo ti: ");
    scanf ("%f",&t1_aux.dlt);

    printf ("Digite o valor do tempo tfinal: ");
    scanf ("%f",&t2_aux.v);
    printf ("Digite o valor do delta do tempo tf: ");
    scanf ("%f",&t2_aux.dlt);

    m1->v=m1_aux.v;
    m1->dlt=m1_aux.dlt;
    m2->v=m2_aux.v;
    m2->dlt=m2_aux.dlt;
    m2_p->v=m2_p_aux.v;
    m2_p->dlt=m2_p_aux.dlt;

    l1->v=l1_aux.v;
    l1->dlt=l1_aux.dlt;
    l2->v=l2_aux.v;
    l2->dlt=l2_aux.dlt;

    t1->v=t1_aux.v;
    t1->dlt=t1_aux.dlt;
    t2->v=t2_aux.v;
    t2->dlt=t2_aux.dlt;

}
/*   printf("%f\n", l1.v);
    printf("%f\n", l1.dlt);
    printf("%f\n", l2.v);
    printf("%f\n", l2.dlt);
    printf("%f\n", m1.v);
    printf("%f\n", m1.dlt);
    printf("%f\n", m2.v);
    printf("%f\n", m2.dlt);
    printf("%f\n", t1.v);
    printf("%f\n", t1.dlt);
    printf("%f\n", t2.v);
    printf("%f\n", t2.dlt);
    */

int main()
{
    grandeza m1, m2, l1, l2, t1, t2;

    parametros_iniciais(&m1,&m2,&l1,&l2,&t1,&t2);

    grandeza v1, v2, p1, p2, i, i1, i2, e1, e2, coe_e, f_med[2], v_cm1, v_cm2;

    float variacao_qtd_movimento, variacao_qtd_energia;

    v1.v=l1.v/t1.v;
    v1.dlt = (l1.dlt*t1.v + l1.v*t1.dlt)/pow(t1.v,2);

    v2.v=l2.v/t2.v;
    v2.dlt = (l2.dlt*t2.v + l2.v*t2.dlt)/pow(t2.v,2);

    p1.v= m1.v*v1.v;
    p1.dlt= m1.dlt*v1.v + m1.v*v1.dlt;

    p2.v=m2.v*v2.v;
    p2.dlt= m2.dlt*v2.v + m2.v*v2.dlt;

    variacao_qtd_movimento=100*modulo(p1.v-p2.v)/p1.v;

    i.v=p2.v - p1.v;
    i.dlt=p2.dlt + p1.dlt;

    i1.v=0-p1.v;
    i1.dlt=p1.dlt;

    i2.v=p2.v-0;
    i2.dlt=p2.dlt;

    e1.v=m1.v*pow(v1.v,2)/2;
    e1.dlt=( m1.dlt*pow(v1.v,2) + m1.v*2*v1.v*v1.dlt )/2;

    e2.v=m2.v*pow(v2.v,2)/2;
    e2.dlt=( m2.dlt*pow(v2.v,2) + m2.v*2*v2.v*v2.dlt )/2;

    coe_e.v= modulo ((v2.v - 0) / (0 - v1.v));
    coe_e.dlt= (v1.dlt*v2.v + v1.v*v1.dlt)/pow (v1.v,2);

    variacao_qtd_energia=100*modulo(e1.v-e2.v)/e1.v;

    f_med[0].v= i1.v/0.001;
    f_med[1].v= i2.v/0.001;

    f_med[0].dlt= i1.dlt/0.001;
    f_med[1].dlt= i2.dlt/0.001;

    v_cm1.v=(m1.v*v1.v)/(m1.v+m2.v);
    v_cm1.dlt=((v1.dlt*m1.v+m1.dlt*v1.v)*(m1.v+m2.v)+(m1.dlt+m2.dlt)*m1.v*v1.v)/pow(m1.v+m2.v, 2);

    v_cm2.v=(m2.v*v2.v)/(m1.v+m2.v);
    v_cm2.dlt=((v2.dlt*m1.v+m1.dlt*v2.v)*(m1.v+m2.v)+(m1.dlt+m2.dlt)*m2.v*v2.v)/pow(m1.v+m2.v, 2);

    printf("Para o referencial no lab:\n");

    printf("Velocidade 1: %f +- %f e velocidade 2: %f +- %f\n", v1.v, v1.dlt, v2.v, v2.dlt);

    printf("Quantidade de movimento 1 (antes): %f +- %f e Qtd. de mov. 2(depois): %f +- %f\n", p1.v, p1.dlt, p2.v, p2.dlt);

    printf("Variacao de quantidade de movimento: %f\n", variacao_qtd_movimento);

    printf("Impulso total: %f +- %f\n", i.v, i.dlt);

    printf("Impulso carrinho 1: %f +- %f, Impulso carro 2: %f +- %f\n", i1.v, i1.dlt, i2.v, i2.dlt);

    printf("Energia cinetica carro 1: %f +- %f, Ec carro 2: %f +- %f\n", e1.v, e1.dlt, e2.v, e2.dlt);

    printf("Coeficiente de restituiçao: %f +- %f\n", coe_e.v, coe_e.dlt);

    printf("Variacao de quantidade de energia: %f\n", variacao_qtd_energia);

    printf("Forca media (carro 1): %f +- %f, F_med (carro 2): %f +- %f\n", f_med[0].v, f_med[0].dlt, f_med[1].v, f_med[1].dlt);

    printf("Velocidade do centro de massa antes do choque: %f +- %f, Vcm depois do choque: %f +- %f\n", v_cm1.v, v_cm1.dlt, v_cm2.v, v_cm2.dlt);

    grandeza u1[2], u2[2], p1_cm[2], p2_cm[2], i_cm, i1_cm, i2_cm, ec_cm[2], coe_e_cm;
    float variacao_qtd_movimento2, variacao_qtd_energia2;

    u1[0].v=v1.v-v_cm1.v;
    u1[0].dlt=v1.dlt+v_cm1.dlt;

    u2[0].v=0-v_cm1.v;
    u2[0].dlt=0+v_cm1.dlt;

    u1[1].v=0-v_cm2.v;
    u1[1].dlt=0+v_cm2.dlt;

    u2[1].v=v2.v-v_cm1.v;
    u2[1].dlt=v2.dlt+v_cm2.dlt;

    p1_cm[0].v= m1.v*u1[0].v;
    p1_cm[0].dlt= m1.dlt*u1[0].v + m1.v*u1[0].dlt;

    p1_cm[1].v= m1.v*u1[1].v;
    p1_cm[1].dlt= m1.dlt*u1[1].v + m1.v*u1[1].dlt;

    p2_cm[0].v=m2.v*u2[0].v;
    p2_cm[0].dlt= m2.dlt*u2[0].v + m2.v*u2[0].dlt;

    p2_cm[1].v=m2.v*u2[1].v;
    p2_cm[1].dlt= m2.dlt*u2[1].v + m2.v*u2[1].dlt;

    variacao_qtd_movimento2=100*modulo((p1_cm[0].v+p2_cm[0].v-p1_cm[1].v-p2_cm[1].v)/(p1_cm[0].v+p2_cm[0].v));

    i_cm.v=p1_cm[1].v+p2_cm[1].v - p1_cm[0].v-p2_cm[0].v;
    i_cm.dlt=p1_cm[1].dlt+p2_cm[1].dlt + p1_cm[0].dlt+p2_cm[0].dlt;

    i1_cm.v=p1_cm[1].v-p1_cm[0].v;
    i1_cm.dlt=p1_cm[1].dlt+p1_cm[0].dlt;

    i2_cm.v=p2_cm[1].v-p2_cm[0].v;
    i2_cm.dlt=p2_cm[1].dlt+p2_cm[0].dlt;

    ec_cm[0].v=m1.v*pow(u1[0].v,2)/2+m2.v*pow(u2[0].v,2)/2;
    ec_cm[0].dlt=( m1.dlt*pow(u1[0].v,2) + m1.v*2*u1[0].v*u1[0].dlt )/2 + ( m2.dlt*pow(u2[0].v,2) + m2.v*2*u2[0].v*u2[0].dlt )/2;

    ec_cm[1].v=m1.v*pow(u1[1].v,2)/2+m2.v*pow(u2[1].v,2)/2;
    ec_cm[1].dlt=( m1.dlt*pow(u1[1].v,2) + m1.v*2*u1[1].v*u1[1].dlt )/2 + ( m2.dlt*pow(u2[1].v,2) + m2.v*2*u2[1].v*u2[1].dlt )/2;


    coe_e_cm.v= modulo ((u2[1].v - u1[1].v) / (u2[0].v - u1[0].v));
    coe_e_cm.dlt= ( (u2[1].dlt + u1[1].dlt) * (u2[0].v - u1[0].v) + (u2[0].dlt + u1[0].dlt) * (u2[1].v - u1[1].v) )/pow ((u2[0].v - u1[0].v),2);

    variacao_qtd_energia2=100*modulo(ec_cm[0].v-ec_cm[1].v)/ec_cm[0].v;


    printf("\nPara o referencial no centro de massa:\n");

    printf("Velocidade 1 inicial: %f +- %f e velocidade 1 final: %f +- %f\n", u1[0].v, u1[0].dlt, u1[1].v, u1[1].dlt);
    printf("Velocidade 2 inicial: %f +- %f e velocidade 2 final: %f +- %f\n", u2[0].v, u2[0].dlt, u2[1].v, u2[1].dlt);

    printf("Quantidade de movimento 1 (antes): %f +- %f e Qtd. de mov. 1 (depois): %f +- %f\n", p1_cm[0].v, p1_cm[0].dlt, p1_cm[1].v, p1_cm[1].dlt);
    printf("Quantidade de movimento 2 (antes): %f +- %f e Qtd. de mov. 2 (depois): %f +- %f\n", p2_cm[0].v, p2_cm[0].dlt, p2_cm[1].v, p2_cm[1].dlt);

    printf("Variacao de quantidade de movimento: %f\n", variacao_qtd_movimento2);

    printf("Impulso total: %f +- %f\n", i_cm.v, i_cm.dlt);

    printf("Impulso carrinho 1: %f +- %f, Impulso carro 2: %f +- %f\n", i1_cm.v, i1_cm.dlt, i2_cm.v, i2_cm.dlt);

    printf("Energia cinetica antes: %f +- %f, Ec depois 2: %f +- %f\n", ec_cm[0].v, ec_cm[0].dlt, ec_cm[1].v, ec_cm[1].dlt);

    printf("Coeficiente de restituiçao: %f +- %f\n", coe_e_cm.v, coe_e_cm.dlt);

    printf("Variacao de quantidade de energia: %f\n", variacao_qtd_energia2);

    grandeza li,lf,mi,mf,ti,tf,m2_p;

    parametros_iniciais2 (&mi,&mf,&li,&lf,&ti,&tf,&m2_p);

    grandeza vp[2], pp[2], ip, ip1, ip2, ec_p[2], coe_e_p;
    float variacao_qtd_movimento3, variacao_qtd_energia3;

    vp[0].v=li.v/ti.v;
    vp[0].dlt = (li.dlt*ti.v + li.v*ti.dlt)/pow(ti.v,2);

    vp[1].v = lf.v/tf.v;
    vp[1].dlt = (lf.dlt*tf.v + lf.v*tf.dlt)/pow(tf.v,2);

    pp[0].v= mi.v*vp[0].v;
    pp[0].dlt= mi.dlt*vp[0].v + mi.v*vp[0].dlt;

    pp[1].v=mf.v*vp[1].v;
    pp[1].dlt= mf.dlt*vp[1].v + mf.v*vp[1].dlt;

    variacao_qtd_movimento3=100*modulo(pp[0].v-pp[1].v)/pp[0].v;

    ip.v=pp[1].v - pp[0].v;
    ip.dlt=pp[1].dlt + pp[0].dlt;

    ip1.v= mi.v*vp[1].v - mi.v*vp[0].v;
    ip1.dlt=mi.v*vp[1].dlt+mi.dlt*vp[1].v + mi.v*vp[0].dlt+mi.dlt*vp[0].v;

    ip2.v=m2_p.v*vp[1].v-0;
    ip2.dlt=m2_p.v*vp[1].dlt+m2_p.dlt*vp[1].v;

    ec_p[0].v=mi.v*pow(vp[0].v,2)/2;
    ec_p[0].dlt=( mi.dlt*pow(vp[0].v,2) + mi.v*2*vp[0].v*vp[0].dlt )/2;

    ec_p[1].v=mf.v*pow(vp[1].v,2)/2;
    ec_p[1].dlt=( mf.dlt*pow(vp[1].v,2) + mf.v*2*vp[1].v*vp[1].dlt )/2;

    coe_e_p.v= modulo ((vp[1].v - vp[1].v) / (0 - vp[0].v));
    coe_e_p.dlt= ((vp[1].dlt+vp[1].dlt)*vp[0].v + (vp[1].v - vp[1].v)*vp[0].dlt ) /pow (vp[0].v,2);

    variacao_qtd_energia3=100*modulo(ec_p[0].v-ec_p[1].v)/ec_p[0].v;

    printf("\nPara a colisao plastica e referencial no lab:\n");

    printf("Velocidade do corpo 1 inicial: %f +- %f e velocidade final dos corpos: %f +- %f\n", vp[0].v, vp[0].dlt, vp[1].v, vp[1].dlt);

    printf("Quantidade de movimento 1 (antes): %f +- %f e Qtd. de mov. 2(depois): %f +- %f\n", pp[0].v, pp[0].dlt, pp[1].v, pp[1].dlt);

    printf("Variacao de quantidade de movimento: %f\n", variacao_qtd_movimento3);

    printf("Impulso total: %f +- %f\n", ip.v, ip.dlt);

    printf("Impulso carrinho 1: %f +- %f, Impulso carro 2: %f +- %f\n", ip1.v, ip1.dlt, ip2.v, ip2.dlt);

    printf("Energia cinetica antes: %f +- %f, Energia cinetica depois: %f +- %f\n", ec_p[0].v, ec_p[0].dlt, ec_p[1].v, ec_p[1].dlt);

    printf("Coeficiente de restituiçao: %f +- %f\n", coe_e_p.v, coe_e_p.dlt);

    printf("Variacao de quantidade de energia: %f\n", variacao_qtd_energia3);

    return 0;
}
